<?php

	require_once('utils/DBUtils.inc');
	require_once('utils/ajaxList.inc');
	require_once('utils/FormUtils.inc');
	require_once('utils/HTMLUtils.inc');
	
	
	// display updated data
	if ($_REQUEST['action'] == 'get_last_messages') {
	
    		$outputList = $GLOBALS['AjaxList']-> displayData(true);

    		require_once('utils/Services_JSON.php');
    		$oJson = new Services_JSON();
    		echo $oJson->encode(array('messages' => $outputList));
    		exit;
    		
	} // end if


	beginHTML("Michael Alterio | Match Drive Test");

	linkCSS("css/header.css");
	linkCSS("css/index.css");
	linkCSS("fonts/fonts.css");
	linkCSS("css/spinner.css");

	linkScript("js/jquery-1.11.0.min.js");
	linkScript("js/submitForm.js");
	linkScript("js/main.js");
	linkScript("js/spinner/overlay.js");
  	linkScript("js/spinner/spin.min.js");

	displayHeader();

	displayPageContainer();

	displayForm();

	// draw chat messages
	$outputList = $GLOBALS['AjaxList']-> displayData();

	echo "<div id='output-container'>$outputList</div>";

?>