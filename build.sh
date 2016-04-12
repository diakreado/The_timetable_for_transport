#!/bin/bash

export PATH=$PATH:/opt/Qt5.5.0/5.5/gcc_64/bin/

build_release_version() {
	cd sources/Timetable_of_trains
	qmake --version
	qmake
	if [ -e "Makefile" ]; then
		make --version
		make
		cd ../..
	else
		echo "Makefile does not exist"
		echo "Build release version failure!"
		exit 1
	fi	
}

build_debug_version() {
	cd sources/Timetable_of_trains
	cloc --version
	cloc --by-file --xml --out=./cloc_result *
	qmake --version
	qmake "QMAKE_CXXFLAGS+=-fprofile-arcs -ftest-coverage -fPIC -O0 -g --coverage" "LIBS+=-lgcov"
	if [ -e "Makefile" ]; then
		make --version
		make
		Test_for_core/tst_test_for_coretest -xml -o test_results || true
		cppcheck --version
		cppcheck --enable=all -v  --xml  * 2> cppcheck_result
		
		valgrind --version
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Timetable_for_train/workspace/tst_test_for_coretest.%p.result /opt/tomcat/.jenkins/jobs/Timetable_for_train/workspace/sources/Timetable_of_trains/Test_for_core/tst_test_for_coretest || true
		
		gcovr --version
		gcovr -r . --xml --exclude='tst*' -o gcovr_result
		cd ../..
	else
		echo "Makefile does not exist"
		echo "Build debug version failure!"
		exit 1
	fi
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
		cd ../..
	else
		echo "Makefile does not exist"
		echo "Report failure!"
		cd ../..
		exit 1
	fi
}

zip_files() {
	if [ -z ${JOB_NAME} ] || [ -z ${BUILD_NUMBER}]; then
		echo "Vars JOB_NAME/BUILD_NUMBER are unset"
		echo "Zip failure!"
		exit 1
	fi

	TITLE="${JOB_NAME}${BUILD_NUMBER}"
	mkdir "$TITLE"

	if [ -e "sources/Timetable_of_trains/Console_for_timetable/Console_for_timetable" ]; then
		cp sources/Timetable_of_trains/Console_for_timetable/Console_for_timetable $TITLE/The_timetable_for_transport${BUILD_NUMBER}
		if [ -e "report/Timetable_of_trains.pdf" ]; then
			cp report/Timetable_of_trains.pdf $TITLE/Timetable_of_trains${BUILD_NUMBER}.pdf
		fi
		if [ -e "report/latex/refman.pdf" ]; then
			cp report/latex/refman.pdf $TITLE/Timetable_of_trainsDoxygen${BUILD_NUMBER}.pdf
		fi
		zip --version
		zip $TITLE.zip $TITLE/*
	else
		echo "ConsoleApp does not exist"
		echo "Zip failure!"
		exit 1
	fi

}

clean() {
	git clean -f -e *.zip
}
