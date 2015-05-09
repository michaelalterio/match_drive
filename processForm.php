<?php session_start(); ?>
<?php

	require_once('utils/DBUtils.inc');
	require_once('utils/ajaxList.inc');

	$GLOBALS['AjaxList']->getData();
?>