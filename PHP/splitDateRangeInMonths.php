<?php
function getMonthRanges($start, $end) {
    $timeStart = strtotime($start);
    $timeEnd   = strtotime($end);
    $out       = [];

    $milestones[] = $timeStart;
    $timeEndMonth = strtotime('first day of next month midnight', $timeStart);
    while ($timeEndMonth < $timeEnd) {
        $milestones[] = $timeEndMonth;
        $timeEndMonth = strtotime('+1 month', $timeEndMonth);
    }
    $milestones[] = $timeEnd;

    $count = count($milestones);
    for ($i = 1; $i < $count; $i++) {
        $out[] = [
            'start' => date('Y-m-d',$milestones[$i - 1]),
            'end'   => date('Y-m-d',$milestones[$i] - 1)
        ];
    }

    return $out;
}

$result = getMonthRanges('2019-01-01', '2019-12-18');

$count = count($result);
$i = 1;
echo "Previous months:",PHP_EOL;
foreach($result as $key => $val) {
	if($i == $count) {
		echo "Current month:",PHP_EOL;
		echo "Start ".$val['start']." - end ".$val['end'],PHP_EOL;
	} 
	else {
		echo "Start ".$val['start']." - end ".$val['end'],PHP_EOL;
	}
	$i++;
}
