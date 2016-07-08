<?php
function probToDie($d, $h){ return ($h > $d) ? probToDie($d, $h-$d)/$d : ($d-$h+1)/$d; }

echo probToDie(4,1) . "<br>";
echo probToDie(4,4) . "<br>";
echo probToDie(4,5) . "<br>";
echo probToDie(4,6) . "<br>";
echo probToDie(1,10) . "<br>";
echo probToDie(100,200) . "<br>";
echo probToDie(8,20) . "<br>";
?>