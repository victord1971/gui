
Допустим, при установке Qt, вы выбрали путь: «C:\Qt», в таком случае, в этой папке у вас будут созданы папки 5.0.2, Licenses и т.д.
Устанавливаем следующие переменные окружения:
QTDIR = C:\Qt\5.0.2\msvc2010
QMAKESPEC = win32-msvc2010


В переменную PATH добавляем путь: C:\Qt\5.0.2\msvc2010\bin
Рекомендуется перезагрузить компьютер после сделанных изменений (в Windows же все-таки работаем, ребят)