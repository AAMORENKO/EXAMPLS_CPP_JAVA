
1)������� ������ ������������ ��� �����.
���������:
1-���� ���� ���� ����� ���-�� ������� �� apache_2.4.2-x64-openssl-1.0.1c.
��� ���� �� ����� http://www.anindya.com/tag/x86/ ��� �������� apache_2.4.4-x64-openssl-1.0.1e.msi � ������.

!!! ����� ������� ��� ������ �� �������� ������ ������ ���� ��������������
Be sure that you have installed the Visual C++ 2010 SP1 Redistributable Package x64: VC10 SP1 vcredist_x64.exe 
������� � ��� ���� ������ � �������������.


����, ����������� ����� �����.
2-PHP- ��� ���� ����� ���-�� ������� �� php-5.4.11-Win32-VC9-x64
��� ���� �� ����� http://www.anindya.com/tag/php/ ��� �������� php-5.4.12-Win32-VC9-x64.zip � ������.


����� ���� ��� ��� ������-�������� ��� ������������,
������� �������� ���������:
0.������ ����� D:\arhiv
2. ���������� C:\Apache
3.*�����������*C:\php 

����������� ������� ����� ������, ����� ��� ���.


���������� ��� ������

������������� ����

)������������� ����.
������� ������� ����� Apache �� ����� �. � ��� ��������� �������� C:/Apache/

2)������������� php
����� ������� ����� php �� ����� � � ������������� ���� ����� � php.
����� ���� php.ini-production ��������������� � php.ini.

����� ����������� ������� php.ini , ����� httpd.
� ����� php ������ ���� ����� tmp.
����� �������� ��� ���- ���� ������� ������������� php.ini-development(�� ���� ������ -development) � ����� ��� ������� ��� � �������� ��� ����������.



����������� ������� ����� ������, ����� ��� ���.


�������������� php.ini
��������� ��� (php.ini) � �����������

����������- ���� �� ��� ���� ��� ������ �����- ����.
����� ������������� ����� � ��� � php � ���������� � ������ ����� �.
�������� php-production.ini � ��������� �� ������� ���� .����� ��������������� � php.ini.��������� ���� php.ini.
� ����� � 
;extension

������ ����

� �����
extension=php_soap.dll
;extension=php_sockets.dll
extension=php_sqlite.dll
extension=php_sqlite3.dll
;extension=php_sybase_ct.dll
;extension=php_tidy.dll
extension=php_xmlrpc.dll
extension=php_xsl.dll
extension=php_zip.dll
1)��� 197 �����

engine = On

2)���� ������ 

short_open_tag = Off

�������� ��

short_open_tag = On

3)��� 215 �����

asp_tags = Off

4)��� 219 �����

precision = 14

5)��� 243 �����

output_buffering = 4096

6)��� 270 �����

zlib.output_compression = Off 7)��� 288 �����

implicit_flush = Off 8)��� 270 �����

���. 9)���� ������ 

display_errors = Off

������ �� 

display_errors = On

10)���� ������ 

display_startup_errors = Off

������ �� 

display_startup_errors = On

11)���� ������ 

post_max_size = 8M

������ �� 

post_max_size = 800M

11)���� ���� 

default_mimetype = "text/html"
; PHP's default character set is set to empty.
; http://php.net/default-charset

�� ��� �����

;default_charset = "UTF-8"

������� ����������� �� ���� ������ ���� ���

default_charset = "UTF-8"

12)����� �� ������� ������ doc_root = � user_dir = ���� ����� ��������� ����� �����

; extension_dir = "ext"

��� ��� �� �����;(��� 731 ������)

extension_dir = "C:\PHP\ext\"

13) 736 ������ enable_dl = Off ������ �� enable_dl = On

14)���� ������ 

file_uploads = On

����� 

;upload_tmp_dir =

��� ��� �����

upload_tmp_dir = "C:\php\upload\"

���� ��� ������ 800

upload_max_filesize = 2M

������ �� 

upload_max_filesize = 800M

15)���� �� ������ ������� ���� �� ����� ������������ � :

;extension=php

��������� ������ ���� �����������������:

extension=php_bz2.dll
extension=php_curl.dll
extension=php_fileinfo.dll
extension=php_gd2.dll
extension=php_gettext.dll
extension=php_gmp.dll
extension=php_intl.dll
extension=php_imap.dll
extension=php_interbase.dll

����� ��������� ������ ���� ���� �����������������:

extension=php_mysql.dll
extension=php_mysqli.dll

extension=php_pdo_firebird.dll
extension=php_pdo_mysql.dll

extension=php_pdo_sqlite.dll

extension=php_sqlite3.dll

extension=php_xmlrpc.dll

extension=php_zip.dll

16)����� �� ������� 

[Date]

� ����� ����� ����� [filter] ����������

date.timezone = "Europe/Moscow"

17)���� [mysqlnd]

mysqlnd.collect_memory_statistics = Off

������ �� 

mysqlnd.collect_memory_statistics = On

18)���� [Session]

���� 

;session.save_path = "/tmp"

��� ��� �����

session.save_path = "c:\php\tmp"

19)���� 1493 ������ 

session.bug_compat_42 = Off

������ �� 

session.bug_compat_42 = On 

������ 1502

session.bug_compat_warn = Off

������ ��

session.bug_compat_warn = On

����� ����������� � ��������� ���� php.ini � ������ ��� � ����� ��� � ��� ����� php-development.ini � php-production.ini .�� ���� c:/php



�������������� httpd

1)� ���.37 ������ ����
ServerRoot "C:/Apache"

2)� ���.58 ������ ����
Listen 80

3)����� � ����������������� ������ 
LoadModule rewrite_module modules/mod_rewrite.so

4)��� ������ �������� ������� �������(���������� ���):

PHPIniDir "C:/php"
AddType application/x-httpd-php phtml php 
LoadModule php5_module c:/php/php5apache2_4.dll

5)� ������ ServerAdmin �����

ServerAdmin shredingoffer@mail.ru

6)����� ����� ����������������� #ServerName localhost:80 ���� ���� (��� 220).

< Directory />
AllowOverride none
Require all denied
< /Directory>

�� ������ ����� 
# Deny access to the entirety of your server's filesystem. You must
# explicitly permit access to web content directories in other 
# blocks below.
#

��� ������ ��:

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

7)� ������ 247 ��� DocumentRoot

DocumentRoot "C:/Apache/htdocs"

8)����� ���� 
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

������ �� ����

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

9)������� ����:

<IfModule dir_module>
DirectoryIndex index.html
</IfModule>

� ������ ��� �� 

<IfModule dir_module>
DirectoryIndex index.html index.htm index.shtml index.php
</IfModule>

10)������� ����:

<Files ".ht*">
Require all denied
</Files >

� ������ ��� �� 

<Files ".ht*">
#Require all denied
Order allow,deny
Deny from all
Satisfy All
</Files>

11)����� �����:

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

�����

DefaultType text/plain

12)������� ���� ������������ � :


#
# TypesConfig points to the file containing the list of mappings from
# filename extension to MIME-type.
#
� ��� ����� �����:

#AddType text/html .shtml
#AddOutputFilter INCLUDES .shtml

����������:

AddEncoding x-compress .Z
AddEncoding x-gzip .gz .tgz

AddType application/x-compress .Z
AddType application/x-gzip .gz .tgz

AddType text/html .shtml
AddOutputFilter INCLUDES .shtml

AddType application/x-httpd-php .php
AddType application/x-httpd-php-source .phps
AddDefaultCharset UTF-8

13)� ����� ����� ������� ����������� ����������� �����:


# �����, � ������� ����� ������ ������ �����.
DocumentRoot "D:/arhiv"
# ����� �� �������� �� ������� ���������� � ������������ �����.
ServerName arhiv.ru
# ����� (���������� ���) ������.
ServerAlias www.arhiv.ru
# ����, � ������� ����� ������������ ������.
ErrorLog "D:/arhiv/error.log"
# # ���� ������� ������� � �����.
CustomLog "D:/arhiv/access.log" common



# �����, � ������� ����� ������ ������ �����.
DocumentRoot "C:/Apache/htdocs"
# ����� �� �������� �� ������� ���������� � ������������ �����.
ServerName localhost
# ����� (���������� ���) ������.
ServerAlias localhost
# ����, � ������� ����� ������������ ������.
ErrorLog "C:/Apache/htdocs/error.log"
# ���� ������� ������� � �����.
CustomLog "C:/Apache/htdocs/access.log" common

AccessFileName .htaccess





4


������ ����� HOSTS
������� � �:/Windows/ System32/drivers/etc/ � ��� �������� �� ������� ���� host .��������� ��� � ����� � ��� ����� 
127.0.0.1 localhost
# ::1 localhost
127.0.0.1 arhiv.ru
127.0.0.1 www.arhiv.ru
� ������������� ��� �������-������� ������ ������ ���� ����.
����� ������������� �������.