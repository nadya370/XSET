Action()
{

	lr_start_transaction("UC_06_UserRegistration");
	
	lr_think_time(5);
	
	lr_start_transaction("open_home_page");
	
	web_reg_find("Fail=NotFound",
			"Text/IC=Welcome to the Web Tours site.",
			LAST);
	
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Not?A_Brand\";v=\"8\", \"Chromium\";v=\"108\", \"Google Chrome\";v=\"108\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");
	
	/*Correlation comment - Do not change!  Original value='135571.526204941zQHDtzApDHQVzzzHtVitApHzccHf' Name ='userSession' Type ='ResponseBased'*/
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


	homepage();
	
	lr_end_transaction("open_home_page",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("user_registration");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=User Information",
		LAST);

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("user_registration",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("customer_profile");
	
	lr_save_string(lr_eval_string("{randomName}{randomPart}{randomPart2}{randomPart3}{randomName}{randomPart}{randomPart2}{randomPart3}"), "username_rnd");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Thank you, <b>{username_rnd}</b>",
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_submit_data("login.pl_2", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={username_rnd}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value={username_rnd}", ENDITEM, 
		"Name=lastName", "Value={randomLast}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=register.x", "Value=64", ENDITEM, 
		"Name=register.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("customer_profile",LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("home");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Welcome to Web Tours",
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("home",LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("logout");
	
	web_reg_find("Fail=NotFound",
			"Text/IC=Welcome to the Web Tours site.",
			LAST);
	
	web_revert_auto_header("Sec-Fetch-User");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("UC_06_UserRegistration",LR_AUTO);

	return 0;
}