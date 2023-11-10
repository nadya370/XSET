Action()
{
	lr_start_transaction("UC_01_LoginLogout");

	lr_think_time(5);
	
	lr_start_transaction("open_home_page");
	
	web_reg_find("Fail=NotFound",
			"Text/IC=Welcome to the Web Tours site.",
			LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='137586.852895909HAHHVcDpHtfiDDDDtctzcpHtctHf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("open_home_page", LR_AUTO);


	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	lr_think_time(5);

	lr_start_transaction("login");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

/*Correlation comment - Do not change!  Original value='page' Name ='CorrelationParameter' Type ='RecordReplay'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter",
		"RegExp=nav\\.pl\\?(\\w+)=",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/login.pl*",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=44", ENDITEM,
		"Name=login.y", "Value=8", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("choose_flight");
	
	web_reg_find("Text/IC= User has returned to the search page.",
		LAST);

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("Search Flights Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?{CorrelationParameter}=search",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?{CorrelationParameter}=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("choose_flight",LR_AUTO);
	
	lr_end_transaction("UC_01_LoginLogout", LR_AUTO);

	return 0;

}