Action()
{

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

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("user_registration");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(24);

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

	lr_start_transaction("customer_profile");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(75);

	web_submit_data("login.pl_2", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=222", ENDITEM, 
		"Name=password", "Value=222", ENDITEM, 
		"Name=passwordConfirm", "Value=222", ENDITEM, 
		"Name=firstName", "Value=222", ENDITEM, 
		"Name=lastName", "Value=222", ENDITEM, 
		"Name=address1", "Value=222", ENDITEM, 
		"Name=address2", "Value=222", ENDITEM, 
		"Name=register.x", "Value=64", ENDITEM, 
		"Name=register.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("customer_profile",LR_AUTO);

	lr_start_transaction("home");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(32);

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

	lr_start_transaction("logout");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(28);

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

	return 0;
}