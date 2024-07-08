El archivo build ya esta compilado con todas las pruebas .cpp incluidas en la carpeta "tests". Si es que se hiciese algun cambio en alguna de estas carpetas, para que nuevamente se compilen las pruebas seguir estos comandos:

PARA LA TERMINAL en: 
PS D:\Documents\Angela - University Of London\COURSES\Algorithms and Data Structures II\WEEK10\MIDTERM\Posfix++\build>

> cmake --build . --config Release
> cd Release 
> ls
(veras la lista de pruebas ejecutables)
test_postfix_evaluator.exe
test_stack.exe
test_symbol_table.exe

> ./test_postfix_evaluator.exe 
(para ejecutar cualquiera de ellas)