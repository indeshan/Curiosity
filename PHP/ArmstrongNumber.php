<?php

	function armstrongNumber($num) {
		$total = 0;
		$x = $num;
		while($x != 0) {
			$rem = $x % 10;
			$total = $total + $rem * $rem * $rem;
			$x = $x / 10;
		}

		if($num == $total) {
			echo "Given number is an Armstrong number";
		}
		else {
			echo "Given number is not an armstrong number";
		}
	}

	armstrongNumber(407);

?>