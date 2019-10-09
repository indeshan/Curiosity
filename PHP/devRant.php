<?php
	$handle = curl_init();
	$url = "https://www.devrant.io/api/devrant/search?app=3&term=".$_REQUEST['term']; 
	// Set the url
	curl_setopt($handle, CURLOPT_URL, $url);
	// Set the result output to be a string.
	curl_setopt($handle, CURLOPT_RETURNTRANSFER, true); 
	$output = curl_exec($handle);
	curl_close($handle);
	//var_dump($output);
	$response = json_decode($output,true);
	//print_r($response);die;
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Dev Rant</title>
		<style>
			img {
				width: 300px;
			}
		</style>
	</head>
	<body>
		<?foreach($response['results'] as $key => $val) {?>
			<img src=<? echo $val['attached_image']['url'];?> /><br> 
		<?}?>
	</body>
</html>
