<?php

$name=$_GET["name"];
$money=$_GET["money"];
$status=$_GET["status"];
if($name!="") {
    if ($status == "" && $money == "")
        req($name);
    else addf($name, $money, $status);
}
else echo "Name ?";
function req($name)
{
    $moneysum=0;
    $moneysumwoblock=0;
    $negativemoney=0;
    $posetivmoney=0;
        $bdlink=mysql_connect("localhost","root","");
        if(!$bdlink)
        {
            echo "not connect".mysql_errno();
            exit;
        }
        if (!mysql_select_db("Bank")){
            echo "not BD".mysql_error();
            exit;
        }
        $result = mysql_query("SELECT * FROM Skore",$bdlink);

        if (!$result) {
            echo "not res" . mysql_error();
            exit;
        }
        if (mysql_num_rows($result) == 0) {
            echo "empty";
            exit;
        }
        while($temp=mysql_fetch_assoc($result)){
        if(mb_strtolower($temp["Name_user"])==mb_strtolower($name)) {
            echo "Skore ID ".$temp["ID"] . "  ";
            echo "Name   ".$temp["Name_user"] . "  ";
            echo "Money  ".$temp["Money"] . "  ";
            echo "Status ".$temp["Status"] . "  <br>";
            $moneysum += $temp["Money"];

            if($temp["Status"]=="active")
                $moneysumwoblock+=$temp["Money"];

            if($temp["Money"]>=0)
                $posetivmoney+=$temp["Money"];
            else  $negativemoney+=$temp["Money"];
        }
        }echo "all money ".$moneysum;
        echo "<br> all money w/o block ".$moneysumwoblock;
        echo "<br>-money ".$negativemoney;
        echo "<br>+money ".$posetivmoney;
}

function addf($name,$money,$status){

    $bdlink=mysql_connect("localhost","root","");
    if(!$bdlink)
    {
        echo "not connect".mysql_errno();
        exit;
    }
    if (!mysql_select_db("Bank")){
        echo "not BD".mysql_error();
        exit;
    }
    $result = mysql_query("INSERT INTO Skore(Name_user, Money, Status) VALUE (\"$name\",$money,\"$status\")",$bdlink);
    echo mysql_error();
    if($result)
        echo "insert seccessfull";
    else "insert fail";
}