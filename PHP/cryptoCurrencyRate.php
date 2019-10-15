<?php
	$decoded_json = json_decode(file_get_contents("https://api.coinmarketcap.com/v1/ticker/"),TRUE);

	function price($curr) {
		global $decoded_json;
		$js = array_column($decoded_json, 'price_usd', 'id');
		return $js[$curr];
	}

	echo 'BTC : '.price("bitcoin");
	echo 'LTC : '.price("litecoin");
	echo 'XMR : '.price("monero");
?>