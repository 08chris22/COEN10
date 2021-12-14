<html>

<body style="text-align:center" bgcolor="blue" text="white">

        <h1>Test Your Guessing Skills!</h1>

	<?php

                $guess = $_POST["guess"];
                $flag = 0;

                echo "The correct numbers are: ";

                for ($i = 0; $i < 5; $i++){
                        $arr[$i] = rand(1,20);
                        echo "$arr[$i] ";
			}
			echo "<br>";

                for ($i = 0; $i < 5; $i++)
                        if ($guess == $arr[$i])
                                $flag = 1;
  
                        if ($flag == 1)
                                echo "Great Job! You got it!";

                        else
                                echo "Sorry Try Again!";

        ?>

        <form method="POST" action="lab3.html">
        <input type="submit" value="Guess Again!"/>
        </form>

</body>
</html>
