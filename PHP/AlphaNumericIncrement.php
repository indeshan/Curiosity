<?php


class AlphaNumericIncrement {
    private $alphabet;

    public function __construct($alphabet)
    {
        $this->alphabet = $alphabet;
    }

    public function getNext($text)
    {
        $length = strlen($text);
        $increment = true;
        for ($i=$length; $i--; $i > 0) {
            $currentCharacter = $text[$i];
            if ($increment) {
                $increment = $this->hasReachEndOfAlphabet($currentCharacter);
                $text[$i] = $this->getIncrementedCharacter($currentCharacter);

            }
        }

        return $text;
    }

    private function getIncrementedCharacter($currentCharacter)
    {
        $position = strpos($this->alphabet, $currentCharacter);
        if (!$this->hasReachEndOfAlphabet($currentCharacter)) {
            return $this->alphabet[++$position];
        }

        return $this->alphabet[0];
    }

    private function hasReachEndOfAlphabet($currentCharacter)
    {
        $position = strpos($this->alphabet, $currentCharacter);
        if ($position < strlen($this->alphabet) -1) {
            return false;
        }

        return true;
    }
} //end of class

$text = "shan9";
$alphabet = "0123456789";
for ($i=97;$i<=122;$i++) {
    $alphabet .= chr($i);
}
$increment = new AlphaNumericIncrement($alphabet);
$next = $increment->getNext($text);

print_r($next.PHP_EOL);
