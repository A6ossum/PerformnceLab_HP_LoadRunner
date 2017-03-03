Action()
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

	lr_think_time(14);

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
		"Name=csrf_token", "Value=b327eadf3a5dd6d9dfadeee254e711ba23c5dcf1", ENDITEM, 
		"Name=req_username", "Value=gorelka", ENDITEM, 
		"Name=req_password", "Value=ekmnbvfnev", ENDITEM, 
		"Name=login", "Value=Login", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);

	lr_think_time(67);

	lr_start_transaction("UC01_TR02_Jump_Test_forum");

	web_url("Test forum", 
		"URL=http://nbnote.ru/pbb/viewforum.php?id=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/index.php?login=1", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_Jump_Test_forum",LR_AUTO);

	lr_start_transaction("UC01_TR03_Jump_Search");

	lr_end_transaction("UC01_TR03_Jump_Search",LR_AUTO);

	lr_start_transaction("UC01_TR04_Search_Input_Topic");

	web_url("search.php", 
		"URL=http://nbnote.ru/pbb/search.php?action=search&keywords=topic&search=Search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/search.php", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR04_Search_Input_Topic",LR_AUTO);

	lr_think_time(51);

	lr_start_transaction("UC01_TR05_Jump_Random_Topic_1");

	web_url("Topic: test 2 topic", 
		"URL=http://nbnote.ru/pbb/viewtopic.php?id=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/search.php?search_id=1660404996", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR05_Jump_Random_Topic_1",LR_AUTO);

	web_url("search.php_2", 
		"URL=http://nbnote.ru/pbb/search.php?action=search&keywords=topic&search=Search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/search.php", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(26);

	lr_start_transaction("UC01_TR)6_Jump_Random_Topic_2");

	web_url("Topic: test 1 topic", 
		"URL=http://nbnote.ru/pbb/viewtopic.php?id=8", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/search.php?search_id=175202299", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR)6_Jump_Random_Topic_2",LR_AUTO);

	web_url("search.php_3", 
		"URL=http://nbnote.ru/pbb/search.php?action=search&keywords=topic&search=Search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/search.php", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(47);

	lr_start_transaction("UC01_TR07_Jump_Random_Topic_3");

	web_url("Topic: Hard Rock topic!", 
		"URL=http://nbnote.ru/pbb/viewtopic.php?id=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/search.php?search_id=1304637159", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR07_Jump_Random_Topic_3",LR_AUTO);

	lr_start_transaction("UC01_TR07_Send_Comment_Topic_3");

	web_submit_data("post.php", 
		"Action=http://nbnote.ru/pbb/post.php?tid=7", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/viewtopic.php?id=7", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=form_sent", "Value=1", ENDITEM, 
		"Name=form_user", "Value=gorelka", ENDITEM, 
		"Name=csrf_token", "Value=a95a84fdd73382764a025199b8ad34eafd975430", ENDITEM, 
		"Name=req_message", "Value=Comment", ENDITEM, 
		"Name=submit_button", "Value=Submit", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR07_Send_Comment_Topic_3",LR_AUTO);

	lr_start_transaction("UC01_TR08_Logout");

	web_url("Logout", 
		"URL=http://nbnote.ru/pbb/login.php?action=out&id=37&csrf_token=0447d3ca4c3390061b73581ab66c46e1322929d6", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/viewtopic.php?pid=524", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR08_Logout",LR_AUTO);

	return 0;
}