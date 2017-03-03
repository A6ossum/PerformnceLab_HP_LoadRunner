vuser_end()
{
	
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
