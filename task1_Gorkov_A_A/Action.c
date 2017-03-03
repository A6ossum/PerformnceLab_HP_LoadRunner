Action()
{		
	int success_search = 0; // flag for success or non success search
	int i = 0; // variable for cycle
	
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

	lr_start_transaction("UC01_TR033_Jump_Search");

	lr_end_transaction("UC01_TR033_Jump_Search",LR_AUTO);

	lr_start_transaction("UC01_TR03_Search_Input_Topic");
	
	//Check if search success. If not success then output error message, close transaction and actions...
	//but will be error when start logout transaction... don't know why
	//i.e. bad search = break logout transaction
	if (web_reg_find("Text=Posts found:", "Search=Body", LAST) == 0) { // if text founded
		//Find list links of search with search keyword {search}
		//Example text of list_search_link - """<a class="permalink" rel="bookmark" title="Permanent link to this topic" href="http://nbnote.ru/pbb/viewtopic.php?id=8">"""
		web_reg_save_param("list_search_link",
							"LB=<a class=\"permalink\" rel=\"bookmark\" title=\"Permanent link to this topic\" href=\"",
							"RB=\">",
							"Ord=All",
							LAST);	
		success_search = 1; // search success
	} else {
		success_search = 0; // search non success
		lr_error_message("Search on failed");
		lr_end_transaction("UC01_TR03_Search_Input_Topic",LR_AUTO);
        return(0);
	}	
	
	web_url("search.php", 
		"URL=http://nbnote.ru/pbb/search.php?action=search&keywords={search}&search=Search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://nbnote.ru/pbb/search.php", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);  

	lr_end_transaction("UC01_TR03_Search_Input_Topic",LR_AUTO);

	lr_think_time(1.54);	
	
	// Check result  
	if (success_search) {
/*-------------------------------Jump on two random link---------------------------------*/
		for (i = 0; i < 2; i++) {
			func_random_link(); // extract random link
			
			lr_start_transaction("UC01_TR04_Jump_Random_Topic");
			
			//Find topic_theme
			//Example text of topic_theme - """<title>Topic Hodor! (Page 1)"""
			web_reg_save_param("topic_theme",
								"LB=<title>",
								"RB= (Page 1)",
								LAST);
			
			web_url("{topic_theme}", 
				"URL={random_link}", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=", 
				"Snapshot=t7.inf", 
				"Mode=HTML", 
				LAST);
		
			lr_end_transaction("UC01_TR04_Jump_Random_Topic",LR_AUTO);
		
			lr_think_time(1.54); // double think_time
		}
/*-------------------------------End jump on two random link---------------------------------*/	

/*-------------------------------Send comment in random link---------------------------------*/
		func_random_link(); // extract random link
		lr_start_transaction("UC01_TR06_Jump_Random_Topic_3");		
		
		//Find posting_tid
		//Example text of posting_tid - """<a class="newpost" href="http://nbnote.ru/pbb/post.php?tid=7">"""
		web_reg_save_param("posting_tid",
							"LB=<a class=\"newpost\" href=\"",
							"RB=\">",
							LAST);
		
		//Find topic_theme
		//Example text of topic_theme - """<title>Topic Hodor! (Page 1)"""
		web_reg_save_param("topic_theme",
							"LB=<title>",
							"RB= (Page 1)",
							LAST);		
		
		web_url("{topic_theme}", 
			"URL={random_link}", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t11.inf", 
			"Mode=HTML", 
			LAST);
	
		lr_end_transaction("UC01_TR06_Jump_Random_Topic_3",LR_AUTO);	
		
		lr_think_time(1.54);
		
		lr_start_transaction("UC01_TR07_Send_Comment_Topic_3");
	
		//Find csrf_token
		//Example text of csrf_token - """"csrf_token" value="a95a84fdd73382764a025199b8ad34eafd975430" />"""
		web_reg_save_param("token_csrf_2",
							"LB=\"csrf_token\" value=\"",
							"RB=\" />",
							LAST);	
		
		web_submit_data("post.php", 
			"Action={posting_tid}", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer={random_link}", 
			"Snapshot=t12.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=form_sent", "Value=1", ENDITEM, 
			"Name=form_user", "Value={username}", ENDITEM, 
			"Name=csrf_token", "Value={token_csrf_2}", ENDITEM, 
			"Name=req_message", "Value={comment}", ENDITEM, 
			"Name=submit_button", "Value=Submit", ENDITEM, 
			LAST);
	
		lr_end_transaction("UC01_TR07_Send_Comment_Topic_3",LR_AUTO);	
		
		lr_think_time(1.54);
/*-------------------------------End send comment in random link---------------------------------*/		
	}		
	
	return 0;
}

/*-------------------------------Calculate random link---------------------------------*/
void func_random_link() {
	int  ItemNumCount, RandNum; // "number of link on search stage" and "random number of link"
	char* temp; // storage random link
	char RandNumStr[20]; // it's char format of "RandNum"
	
	//Conversion number to int
	ItemNumCount = atoi(lr_eval_string("{list_search_link_count}"));
	
	//Display array count (for debug)
	//lr_output_message ("Number of Items in List : %s",lr_eval_string("{list_search_link_count}"));		
	
	//Generate a Random Number
	RandNum = 1 + rand() % ItemNumCount;
	
	//SAve Random Number to String 
	itoa (RandNum,RandNumStr,20);
	//lr_output_message("Random Number Generated is :%s", lr_eval_string(RandNumStr));
	
	//Saves RandNumStr into random_number_link
	lr_save_string(RandNumStr, "random_number_link");
	
	temp = lr_eval_string(lr_eval_string("{list_search_link_{random_number_link}}"));
	
	//save random link as parameter {random_link}
	lr_save_string(temp, "random_link");		
}
/*-------------------------------End calculate random link---------------------------------*/