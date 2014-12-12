<?php
 
// Default: http://<host>/<dir>/<filename>.php?iter1=64&width=600&height=400&coef=32
 
function BN($n, $l, $r) {return $n>$l && $n<=$r;}
function SQR($a) {return $a*$a;}
 
define("COEF",	$_GET["coef"]);
$iter1			=		$_GET["iter1"];
$width			=		$_GET["width"];
$height	=		$_GET["height"];
 
header("Content-type: image/png");
 
$img	=	imagecreatetruecolor($width, $height);
$iter2	=	0.01/($width/300);
$yy		=	-1;
 
for ($y = -1; $y < 1; $y = $y + $iter2) {
	$yy++; $xx=-1;
	for($x = -2; $x < 1; $x = $x + $iter2) {
		$xx++;
		$Cx	=	$x;
		$Cy	=	$y;
		$X	=	$x;
		$Y	=	$y;
		$ix	=	0;
		$iy	=	0;
		$n	=	0;
		while ((SQR($ix) + SQR($iy) < 4) and ($n < $iter1)) {
			$ix 	=	SQR($X) - SQR($Y) + $Cx;
			$iy 	=	2*$X*$Y + $Cy;
			$X	=	$ix;
			$Y	=	$iy;
			$n++;
		}
		if(BN($n,0,7))      $col = imagecolorallocate($img,COEF*$n,0,0);
		elseif(BN($n,7,14)) $col = imagecolorallocate($img,COEF*$n,COEF*$n,0);
		elseif(BN($n,14,21))$col = imagecolorallocate($img,COEF*$n,0,COEF*$n);
		elseif(BN($n,21,28))$col = imagecolorallocate($img,0,COEF*$n,0);
		elseif(BN($n,28,35))$col = imagecolorallocate($img,COEF*$n,COEF*$n,0);
		elseif(BN($n,35,42))$col = imagecolorallocate($img,0,COEF*$n,COEF*$n);
		elseif(BN($n,42,49))$col = imagecolorallocate($img,0,0,COEF*$n);
		elseif(BN($n,49,56))$col = imagecolorallocate($img,COEF*$n,0,COEF*$n);
		elseif(BN($n,56,64))$col = imagecolorallocate($img,0,COEF*$n,COEF*$n);
		imagesetpixel($img, $xx, $yy, $col);
	}
}
imagepng($img);
imagedestroy($img);
?>
