<?php
/* Challenge #271 [Easy] Simplifying Fractions
   Given two numbers, the first being the numerator and the second being the denominator of a fraction, reduce
   the fraction to its lowest form

  Golfy?
  2nd function faster than first
*/

function simplify($n,$d){
	for($i=2;$i<=$n&&$i<=$d&&($n%$i>0||$d%$i>0);$i+=1);
	return $i<=$n&&$i<=$d?simplify($n/$i,$d/$i):"{$n}/{$d}";
}

function simplify_faster($n,$d){
	$n0=$n;$d0=$d;
	while($d){
		$no=$n;$n=$d;$d=$no%$d;
	}
	return ($n0/$n)."/".($d0/$n);
}

echo simplify(4,8) . "<br>"; 			//1/2
echo simplify(1536, 78360) . "<br>"; 	//64/3265
echo simplify(51478, 5536) . "<br>"; 	//25739/2768
echo simplify(46410, 119340) . "<br>";	//7/18
echo simplify(7673, 4729) . "<br>"; 	//7673/4729
echo simplify(4096, 1024) . "<br>"; 	//4/1
