Action()
{

	lr_start_transaction("UC_05_DeletingTicket");
	
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

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("open_home_page",LR_AUTO);

	lr_start_transaction("login");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(6);

	web_submit_form("login.pl", 
		"Snapshot=t14.inf", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	
	
	lr_start_transaction("itinerary");
	
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Invoice sent to:",
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(53);
	
	web_reg_save_param("flightID",
		"LB/IC=flightID\" value=\"",
		"RB/IC=\"",
		LAST);
	

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t15.inf", 
		LAST);

	lr_end_transaction("itinerary",LR_AUTO);

	lr_start_transaction("removal");
	

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(62);

	web_reg_find("Fail=Found",
		"Text/IC={flightID}",
		LAST);
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t16.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=56", ENDITEM, 
		"Name=removeFlights.y", "Value=10", ENDITEM,		
		LAST);

	lr_end_transaction("removal",LR_AUTO);
	

	lr_start_transaction("logout");
	
	web_reg_find("Fail=NotFound",
			"Text/IC=Welcome to the Web Tours site.",
			LAST);

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(52);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t18.inf", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	lr_end_transaction("UC_05_DeletingTicket",LR_AUTO);

	return 0;
}