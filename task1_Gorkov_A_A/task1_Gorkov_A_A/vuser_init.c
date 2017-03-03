vuser_init()
{
	
	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=r20swj13mr.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20161027; DOMAIN=r20swj13mr.microsoft.com");

	web_add_cookie("MC1=GUID=48da53fbf38ffe41bb1e0c7e22672de6&HASH=fb53&LV=201701&V=4&LU=1485858170060; DOMAIN=r20swj13mr.microsoft.com");

	web_add_cookie("A=I&I=AxUFAAAAAAAiBwAAoC1nn2hCZiSySd6B+2B0oA!!&V=4; DOMAIN=r20swj13mr.microsoft.com");

	web_add_cookie("MUID=322C45B4F76768E02F604CC2F3676213; DOMAIN=r20swj13mr.microsoft.com");

	web_url("index.php", 
		"URL=http://nbnote.ru/pbb/index.php", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../favicon.ico", "Referer=", ENDITEM, 
		"Url=https://r20swj13mr.microsoft.com/ieblocklist/v1/urlblockindex.bin", "Referer=", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20161027; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MC1=GUID=48da53fbf38ffe41bb1e0c7e22672de6&HASH=fb53&LV=201701&V=4&LU=1485858170060; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("A=I&I=AxUFAAAAAAAiBwAAoC1nn2hCZiSySd6B+2B0oA!!&V=4; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MUID=322C45B4F76768E02F604CC2F3676213; DOMAIN=iecvlist.microsoft.com");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1387494476607/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC01_TR01_Login");

	web_add_cookie("SRCHUID=V=2&GUID=DBFD70F648584B0D878C344EDCFAEE9C; DOMAIN=ieonline.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=ieonline.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20161027; DOMAIN=ieonline.microsoft.com");

	web_add_cookie("MC1=GUID=48da53fbf38ffe41bb1e0c7e22672de6&HASH=fb53&LV=201701&V=4&LU=1485858170060; DOMAIN=ieonline.microsoft.com");

	web_add_cookie("A=I&I=AxUFAAAAAAAiBwAAoC1nn2hCZiSySd6B+2B0oA!!&V=4; DOMAIN=ieonline.microsoft.com");

	web_add_cookie("MUID=322C45B4F76768E02F604CC2F3676213; DOMAIN=ieonline.microsoft.com");

	lr_think_time(1.54);
	
	//Find csrf_token
	//Example text of csrf_token - """"csrf_token" value="7891d9c05fcfe910d63cfcfbda6ad26ce337067c" />"""
	web_reg_save_param("token_csrf_1",
						"LB=\"csrf_token\" value=\"",
						"RB=\" />",
						LAST);

	web_url("login.php", 
		"URL=http://nbnote.ru/pbb/login.php", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/index.php", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=style/Oxygen/font/responsivenav.eot", ENDITEM, 
		"Url=https://ieonline.microsoft.com/iedomainsuggestions/ie11/suggestions.ru-RU", "Referer=", ENDITEM, 
		LAST);
	

	web_submit_data("login.php_2", 
		"Action=http://nbnote.ru/pbb/login.php", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/login.php", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=form_sent", "Value=1", ENDITEM, 
		"Name=redirect_url", "Value=http://nbnote.ru/pbb/index.php", ENDITEM, 
		"Name=csrf_token", "Value={token_csrf_1}", ENDITEM, 
		"Name=req_username", "Value={username}", ENDITEM, 
		"Name=req_password", "Value={password}", ENDITEM, 
		"Name=login", "Value=Login", ENDITEM, 
		LAST);		

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);

	lr_think_time(1.54);
	
	return 0;
}
