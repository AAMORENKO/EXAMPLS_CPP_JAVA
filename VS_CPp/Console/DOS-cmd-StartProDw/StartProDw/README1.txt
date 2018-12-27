
1)Сначала качаем дистрибутивы для всего.
Источники:
1-Апач –нам надо найти что-то похожее на apache_2.4.2-x64-openssl-1.0.1c.
Это есть на сайте http://www.anindya.com/tag/x86/ там выбираем apache_2.4.4-x64-openssl-1.0.1e.msi и качаем.

!!! Здесь заметим что сверху на странице откуда грузим есть предупреждение
Be sure that you have installed the Visual C++ 2010 SP1 Redistributable Package x64: VC10 SP1 vcredist_x64.exe 
Поэтому и его тоже грузим и устанавливаем.


Итак, дистрибутив Апача –есть.
2-PHP- нам надо найти что-то похожее на php-5.4.11-Win32-VC9-x64
Это есть на сайте http://www.anindya.com/tag/php/ там выбираем php-5.4.12-Win32-VC9-x64.zip и качаем.


После того как все закали-закачали все дистрибутивы,
Порядок действий следующий:
0.Создаём папку D:\arhiv
2. установить C:\Apache
3.*распаковать*C:\php 

Редактируем сначала Апаче конфиг, затем рхр ини.


подключаем как модуль

перезагружаем комп

)Устанавливаем апач.
Заранее создаем папку Apache на диске с. А при установке пропишем C:/Apache/

2)Устанавливаем php
Далее создаем папку php на диске с и распаковываем туда архив с php.
Далее файл php.ini-production переименовываем в php.ini.

Затем редактируем сначала php.ini , затем httpd.
В папке php должна быть папка tmp.
Когда изменяем пхп ини- надо сначала переименовать php.ini-development(то есть убрать -development) а затем уже открыть его и изменять его содержимое.



Редактируем сначала Апаче конфиг, затем рхр ини.


Редактирование php.ini
Открываем его (php.ini) и редактируем

Посмотрели- есть ли длл файл для нашего апача- есть.
Далее переименовали папку с пхп в php и перетащили в корень диска с.
Копируем php-production.ini и вставляем на рабочий стол .Затем переименовываем в php.ini.Открываем этот php.ini.
В блоке с 
;extension

Должно быть

В концу
extension=php_soap.dll
;extension=php_sockets.dll
extension=php_sqlite.dll
extension=php_sqlite3.dll
;extension=php_sybase_ct.dll
;extension=php_tidy.dll
extension=php_xmlrpc.dll
extension=php_xsl.dll
extension=php_zip.dll
1)Стр 197 такая

engine = On

2)Ищем строку 

short_open_tag = Off

Изменяем на

short_open_tag = On

3)Стр 215 такая

asp_tags = Off

4)Стр 219 такая

precision = 14

5)Стр 243 такая

output_buffering = 4096

6)Стр 270 такая

zlib.output_compression = Off 7)Стр 288 такая

implicit_flush = Off 8)Стр 270 такая

Итд. 9)Ищем строку 

display_errors = Off

Меняем на 

display_errors = On

10)Ищем строку 

display_startup_errors = Off

Меняем на 

display_startup_errors = On

11)Ищем строку 

post_max_size = 8M

Меняем на 

post_max_size = 800M

11)Ищем блок 

default_mimetype = "text/html"
; PHP's default character set is set to empty.
; http://php.net/default-charset

За ним стоит

;default_charset = "UTF-8"

Убираем комментарий то есть должно быть так

default_charset = "UTF-8"

12)Далее вы увидите строки doc_root = и user_dir = ниже через несколько строк будет

; extension_dir = "ext"

под ней мы пишем;(это 731 строка)

extension_dir = "C:\PHP\ext\"

13) 736 строка enable_dl = Off меняем на enable_dl = On

14)Ищем строку 

file_uploads = On

Далее 

;upload_tmp_dir =

Под ней пишем

upload_tmp_dir = "C:\php\upload\"

Ниже это строка 800

upload_max_filesize = 2M

меняем на 

upload_max_filesize = 800M

15)Ниже мы увидим длинный блок из строк начинающихся с :

;extension=php

Следующие строки надо раскомментировать:

extension=php_bz2.dll
extension=php_curl.dll
extension=php_fileinfo.dll
extension=php_gd2.dll
extension=php_gettext.dll
extension=php_gmp.dll
extension=php_intl.dll
extension=php_imap.dll
extension=php_interbase.dll

Далее следующие строки тоже надо раскомментировать:

extension=php_mysql.dll
extension=php_mysqli.dll

extension=php_pdo_firebird.dll
extension=php_pdo_mysql.dll

extension=php_pdo_sqlite.dll

extension=php_sqlite3.dll

extension=php_xmlrpc.dll

extension=php_zip.dll

16)Далее вы увидите 

[Date]

В самом конце перед [filter] записываем

date.timezone = "Europe/Moscow"

17)Ищем [mysqlnd]

mysqlnd.collect_memory_statistics = Off

Меняем на 

mysqlnd.collect_memory_statistics = On

18)Ищем [Session]

Ищем 

;session.save_path = "/tmp"

под ней пишем

session.save_path = "c:\php\tmp"

19)Ищем 1493 строку 

session.bug_compat_42 = Off

Меняем на 

session.bug_compat_42 = On 

Строку 1502

session.bug_compat_warn = Off

меняем на

session.bug_compat_warn = On

Далее сохраняемся и закрываем этот php.ini и кладем его в папку где у нас лежат php-development.ini и php-production.ini .То есть c:/php



Редактирование httpd

1)В стр.37 должно быть
ServerRoot "C:/Apache"

2)В стр.58 должно быть
Listen 80

3)Найти и раскомментировать строку 
LoadModule rewrite_module modules/mod_rewrite.so

4)Под блоком загрузки модулей вписать(подключаем пхп):

PHPIniDir "C:/php"
AddType application/x-httpd-php phtml php 
LoadModule php5_module c:/php/php5apache2_4.dll

5)В строке ServerAdmin пишем

ServerAdmin shredingoffer@mail.ru

6)Далее после закоментированной #ServerName localhost:80 есть блок (стр 220).

< Directory />
AllowOverride none
Require all denied
< /Directory>

Он стоиит после 
# Deny access to the entirety of your server's filesystem. You must
# explicitly permit access to web content directories in other 
# blocks below.
#

Его меняем на:

< Directory />
Options FollowSymLinks
AllowOverride All
Order deny,allow
Deny from all
< /Directory>
< Directory "d:/arhiv">
Options Indexes FollowSymLinks
AllowOverride All
Order allow,deny
Allow from all
< /Directory>

7)В строке 247 где DocumentRoot

DocumentRoot "C:/Apache/htdocs"

8)Далее блок 
<Directory "C:/Apache/htdocs">
#
# Possible values for the Options directive are "None", "All",
# or any combination of:
# Indexes Includes FollowSymLinks SymLinksifOwnerMatch ExecCGI MultiViews
#
# Note that "MultiViews" must be named *explicitly* --- "Options All"
# doesn't give it to you.
#
# The Options directive is both complicated and important. Please see
# http://httpd.apache.org/docs/2.4/mod/core.html#options
# for more information.
#
Options Indexes FollowSymLinks

#
# AllowOverride controls what directives may be placed in .htaccess files.
# It can be "All", "None", or any combination of the keywords:
# Options FileInfo AuthConfig Limit
#
AllowOverride None

#
# Controls who can get stuff from this server.
#
Require all granted
</Directory>

Меняем на блок

<Directory "C:/Apache/htdocs">
#
# Possible values for the Options directive are "None", "All",
# or any combination of:
# Indexes Includes FollowSymLinks SymLinksifOwnerMatch ExecCGI MultiViews
#
# Note that "MultiViews" must be named *explicitly* --- "Options All"
# doesn't give it to you.
#
# The Options directive is both complicated and important. Please see
# http://httpd.apache.org/docs/2.4/mod/core.html#options
# for more information.
#
Options Indexes FollowSymLinks

#
# AllowOverride controls what directives may be placed in .htaccess files.
# It can be "All", "None", or any combination of the keywords:
# Options FileInfo AuthConfig Limit
#
#AllowOverride None
AllowOverride All
#
# Controls who can get stuff from this server.
#
# Require all granted
Order allow,deny
Allow from all
</Directory>

9)Находим блок:

<IfModule dir_module>
DirectoryIndex index.html
</IfModule>

И меняем его на 

<IfModule dir_module>
DirectoryIndex index.html index.htm index.shtml index.php
</IfModule>

10)Находим блок:

<Files ".ht*">
Require all denied
</Files >

И меняем его на 

<Files ".ht*">
#Require all denied
Order allow,deny
Deny from all
Satisfy All
</Files>

11)После блока:

<IfModule alias_module>
#
# Redirect: Allows you to tell clients about documents that used to 
# exist in your server's namespace, but do not anymore. The client
# will make a new request for the document at its new location.
# Example:
# Redirect permanent /foo http://localhost/bar

#
# Alias: Maps web paths into filesystem paths and is used to
# access content that does not live under the DocumentRoot.
# Example:
# Alias /webpath /full/filesystem/path
#
# If you include a trailing / on /webpath then the server will
# require it to be present in the URL. You will also likely
# need to provide a section to allow access to
# the filesystem path.

#
# ScriptAlias: This controls which directories contain server scripts. 
# ScriptAliases are essentially the same as Aliases, except that
# documents in the target directory are treated as applications and
# run by the server when requested rather than as documents sent to the
# client. The same rules about trailing "/" apply to ScriptAlias
# directives as to Alias.
#
ScriptAlias /cgi-bin/ "C:/Apache/cgi-bin/"
</IfModule>

Пишем

DefaultType text/plain

12)Находим блок начинающийся с :


#
# TypesConfig points to the file containing the list of mappings from
# filename extension to MIME-type.
#
В нем после строк:

#AddType text/html .shtml
#AddOutputFilter INCLUDES .shtml

Дописываем:

AddEncoding x-compress .Z
AddEncoding x-gzip .gz .tgz

AddType application/x-compress .Z
AddType application/x-gzip .gz .tgz

AddType text/html .shtml
AddOutputFilter INCLUDES .shtml

AddType application/x-httpd-php .php
AddType application/x-httpd-php-source .phps
AddDefaultCharset UTF-8

13)В самом конце конфига прописываем виртуальные хосты:


# Папка, в которой будет корень вашего хоста.
DocumentRoot "D:/arhiv"
# Домен по которому вы сможете обращаться к виртуальному хосту.
ServerName arhiv.ru
# Алиас (добавочное имя) домена.
ServerAlias www.arhiv.ru
# Файл, в который будут записываться ошибки.
ErrorLog "D:/arhiv/error.log"
# # Файл журнала доступа к хосту.
CustomLog "D:/arhiv/access.log" common



# Папка, в которой будет корень вашего хоста.
DocumentRoot "C:/Apache/htdocs"
# Домен по которому вы сможете обращаться к виртуальному хосту.
ServerName localhost
# Алиас (добавочное имя) домена.
ServerAlias localhost
# Файл, в который будут записываться ошибки.
ErrorLog "C:/Apache/htdocs/error.log"
# Файл журнала доступа к хосту.
CustomLog "C:/Apache/htdocs/access.log" common

AccessFileName .htaccess





4


Правка файла HOSTS
Заходим в с:/Windows/ System32/drivers/etc/ и там копируем на рабочий стол host .Открываем его и пишем в нем снизу 
127.0.0.1 localhost
# ::1 localhost
127.0.0.1 arhiv.ru
127.0.0.1 www.arhiv.ru
И перетаскиваем его обратно-заранее удалив старый хост файл.
Затем перезагружаем систему.