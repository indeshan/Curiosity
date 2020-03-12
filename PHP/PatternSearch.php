<?php 
	// Search Pattern in given string

	function patternSearch($pattern, $string) {
		$patternLength = strlen($pattern);
		$stringLength = strlen($string);

		for ($i = 0; $i <= $stringLength - $patternLength; $i++) {
			for ($j = 0; $j < $patternLength; $j++)
				if ($string[$i + $j] != $pattern[$j])
					break;
			if ($j == $patternLength)
				echo "Pattern found at position ", $i."\n";
		}
	}

	$string = "ABCCDABCDAAACDA";
	$pattern = "CDA";
	patternSearch($pattern, $string);
?>

