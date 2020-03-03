<?php
	define('FTP_HOST', 'HOST');
	define('FTP_USER', 'USENAME');
	define('FTP_PASS', 'PASSWORD');

	include('FTPClient.php');

	$ftpObj = new FTPClient();

	$ftpObj -> connect(FTP_HOST, FTP_USER, FTP_PASS);

	if ($ftpObj -> connect(FTP_HOST, FTP_USER, FTP_PASS)) {
		echo 'Connected sucessfully!';
	} else {
		echo 'Failed to connect.';
	}

	$dir = 'test';

	$ftpObj->makeDir($dir);

	$fileFrom = 'test.txt';
	$fileTo = $dir . '/' . $fileFrom;
	$ftpObj -> uploadFile($fileFrom, $fileTo);
	$ftpObj->changeDir($dir);
	$contentsArray = $ftpObj->getDirListing();

	echo '<pre>';
	print_r($contentsArray);
	echo '';
	print_r($ftpObj -> getMessages());

?>
