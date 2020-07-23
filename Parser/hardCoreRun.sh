flex scanner.l
bison parser.y -d -o parser.tab.c
if [ $? -eq 1 ]; then
    echo "Bison Parse Error!"
else
    gcc parser.tab.c -o a.out
    if [ $? -eq 1 ]; then
        echo "Code did not Compiler"
    else
        echo "Core compiled successfuly"
        ./a.out tests/Test.in out/Test.out
        if [ $? -eq 0 ]; then
            echo "Code Executed Successfuly!"
            if command -v python3; then
                python3 comp.py -a "out/Test.out" -b "tests/Test.out" -o "report/Test.report.txt"
            else
                python comp.py -a "out/Test.out" -b "tests/Test.out" -o "report/Test.report.txt"
            fi
            if [[ $? = 0 ]]; then
                echo "++++ test passed"
            else
                echo "---- test failed !"
            echo
            fi
        else
            echo "Code did not execute successfuly!"
        fi
    fi
fi
read -r -p "Wait 5 seconds or press any key to continue immediately" -t 5 -n 1 -s
