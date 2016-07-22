<?php
/* Challenge #274 [Intermediate] Calculating De Bruijn Sequences
   Write a function to generate a de Bruijn sequence
   A De Bruijn sequence B(2, 3) (with alphabet 0 and 1) is:
    00010111
   Inputs:
        $k = an integer or a string of unique characters
        $n = the length of subsequences that should be included in the sequence

*/

function DeBruijn($k, $n){
    if(is_int($k)){
        $alph = "";
        for($i=0;$i<$k;$i++){
            $alph .= "$i";
        }
        $k = $alph;
    }
    $lwords = array();
    $lastlword = substr($k,0,1);
    $lwords[] = $lastlword;
    while(strcmp($lastlword, substr($k,-1)) != 0){
        $x = "";
        for($i=1;$i<=$n;$i++){
            $x .= substr($lastlword, ($i % strlen($lastlword))-1, 1);
        }
        while(substr($x,-1) == substr($k,-1) && strlen($x) > 1){
            $x = substr($x,0,-1);
        }
        $lastchar = substr($x,-1);
        $x = substr($x,0,-1) . substr($k,strrpos($k,$lastchar)+1,1);
        $lastlword = $x;
        $lwords[] = $lastlword;
    }

    $seq = "";
    foreach($lwords as $word){
        if($n % strlen($word) == 0){
            $seq .= $word;
        }
    }
    return $seq;
}

?>