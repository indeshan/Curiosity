<?php
function dateRange( $first, $last, $step = '+1 day', $format = 'Y/m/d' ) {

	$dates = array();
	$current = strtotime( $first );
	$last = strtotime( $last );

	while( $current <= $last ) {

		$dates[] = date( $format, $current );
		$current = strtotime( $step, $current );
	}

	return $dates;
}

print_r( dateRange( '2010/07/26', '2010/08/05') );
print_r( dateRange( '2010/07/20', '2010/08/05', '+1 week') );
