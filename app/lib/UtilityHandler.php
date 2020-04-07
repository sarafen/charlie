<?php

class UtilityHandler {

    public function __construct() {
        // set any defaults when you first instantiate the obj
        date_default_timezone_set('America/Chicago');
    }

    public function parseDate($text, $args_arr = null) {

        //expects format 01/19/20 OR 01/19/20|7:30PM

        if (preg_match("/\|/i", $text)) {
            list($date, $time) = explode('|', $text);
            list($month, $day, $year) = explode('/', $date);
            list($hours, $mins) = explode(':', $time);

            if(preg_match("/PM/i", $mins)) {
                $hours = $hours + 12;
            }
        } else {
            list($month, $day, $year) = explode('/', $text);

            $hours = 0;
            $mins = 0;
        }

        $timeStamp = mktime(intval($hours), intval($mins), 0, intval($month), intval($day), intval($year));

        return $timeStamp;

    }

}
