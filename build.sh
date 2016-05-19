#!/bin/bash

export PATH=$PATH:/opt/Qt5.5.0/5.5/gcc_64/bin/

build_release_version() {
	cd sources/Information_about_metro
	qmake --version
	qmake
	if [ -e "Makefile" ]; then
		make --version
		make
	else
		echo "Makefile does not exist"
		echo "Build release version failure!"
		return 1
	fi	
	cd ../..
}

build_debug_version() {
	cd sources/Information_about_metro
	cloc --version
	cloc --by-file --xml --out=./cloc_result *
	qmake --version
	qmake "QMAKE_CXXFLAGS+=-fprofile-arcs -ftest-coverage -fPIC -O0 -g --coverage" "LIBS+=-lgcov"
	if [ -e "Makefile" ]; then
		make --version
		make
		Tests/tst_test_for_coretest -xml -o test_results || true
		cppcheck --version
		cppcheck --enable=all -v  --xml  * 2> cppcheck_result
		
		valgrind --version
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Information_about_metro/workspace/tst_test_for_coretest.%p.result /opt/tomcat/.jenkins/jobs/Information_about_metro/workspace/sources/Information_about_metro/Tests/tst_test_for_coretest || true
		
		gcovr --version
		gcovr -r . --xml --exclude='tst*' -o gcovr_result
	else
		echo "Makefile does not exist"
		echo "Build debug version failure!"
		return 1
	fi
	cd ../..
}

make_report() {
	cd report
		if [ -e "Doxyfile" ]; then
			doxygen --version
			doxygen Doxyfile
		else
			echo "Doxygen failed"
			echo "Doxyfile does not exist"
		fi
	cd latex
	if [ -e "Makefile" ]; then
		make --version
		make

	else
		echo "Makefile does not exist"
		echo "Report failure!"
		return 1
	fi
	cd ../..
}

zip_files() {
	if [ -z ${JOB_NAME} ] || [ -z ${BUILD_NUMBER} ]; then
		echo "Vars JOB_NAME/BUILD_NUMBER are unset"
		echo "Zip failure!"
		return 1
	fi

	TITLE="${JOB_NAME}${BUILD_NUMBER}"
	mkdir "$TITLE"

	if [ -e "sources/Information_about_metro/Console/Console" ]; then
		cp sources/Information_about_metro/Console/Console $TITLE/The_timetable_for_transport${BUILD_NUMBER}
			if [ -e "report/Information_about_metro.pdf" ]; then
				cp report/Information_about_metro.pdf $TITLE/Information_about_metro${BUILD_NUMBER}.pdf
			fi
		if [ -e "report/latex/refman.pdf" ]; then
			cp report/latex/refman.pdf $TITLE/Information_about_metroDoxygen${BUILD_NUMBER}.pdf
		fi
		if [ -e "report/metro_Saint-Petersburg_route_info.txt" ]; then 
			cp report/metro_Saint-Petersburg_route_info.txt $TITLE/metro_Saint-Petersburg_route_info.txt
		fi
		if [ -e "report/metro_Saint-Petersburg.txt" ]; then 
			cp report/metro_Saint-Petersburg_station_info.txt $TITLE/metro_Saint-Petersburg_station_info.txt
		fi
	else
		echo "ConsoleApp does not exist"
		echo "Zip failure!"
		return 1
	fi
	if [ -e "sources/Information_about_metro/GUI/GUI" ]; then
		cp sources/Information_about_metro/GUI/GUI $TITLE/InfoAboutMetroGUI${BUILD_NUMBER}
	else
		echo "GUIApp does not exist"
		echo "Zip failure!"
		exit 1
	fi
			zip --version
		zip $TITLE.zip $TITLE/*

}

clean() {
	git clean -f -e *.zip
}