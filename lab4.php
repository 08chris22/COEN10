<html> 

<body style="text-align:center" bgcolor="blue" text="white">

<h1> Welcome to the Lottery!</h1>

<?php

	$guess1 = $_POST["guess1"];
	$guess2 = $_POST["guess2"];
	$guess3 = $_POST["guess3"];
	$guess4 = $_POST["guess4"];
	$guess5 = $_POST["guess5"];
	$guesses = array($guess1,$guess2,$guess3,$guess4,$guess5);

	echo "You entered the values: ";

	for ($i = 0; $i < 5; $i++) {     //Creating the array with the user's guesses.
	
		echo "$guesses[$i] ";
		}

	echo "<br>";

	echo "The correct numbers are: ";

	for ($j = 0; $j < 5; $j++)        //Creating the array with the answers.
	{
		$ans[$j] = rand(1, 20);        //Making sure the answers are random.
		for($k = $j-1; $k >= 0; $k--) 	// Checking if any of the numbers are repeating.
		{
			if($ans[$j] == $ans[$k])      
			{
				$j--;
				break;
			}
		}	
	}
	for($l = 0; $l < 5; $l++) {
		echo "$ans[$l] ";
	}
	echo "<br>";

	$counter = 0;        //Implementing a score counter.

	for($m = 0; $m < 5; $m++) {
		for($n = 0; $n < 5; $n++) {
			if($guesses[$m] == $ans[$n]) {      //Checking how many numbers the user got correct.
				$counter++;
	}}}
	echo "You got $counter correct numbers!";     //Outputing to the user.

?>

<form method="POST" action="lab4.html">
<input type="submit" value="Play Again!"/>
</form>

</body>
</html>
