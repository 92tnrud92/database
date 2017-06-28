   
<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <title>DB</title>
    <style>
     a:link {
     color: black;
     background-color: transparent;
     text-decoration: none;
     }
     a:visited {
     color: gray;
     background-color: transparent;
     text-decoration: none;
     }
     a:hover {
     color: gray;
     background-color: transparent;
     text-decoration: underline;
     }
     a:active {
     color: black;
     background-color: transparent;
     text-decoration: underline;
     }
      #jb-container {
        width: 940px;
        height: 450px;
        margin: 0px ;
        padding: 20px;
        border: 1px solid #bcbcbc;
      }
      #jb-header {
        padding: 20px;
        margin-bottom: 20px;
        border: 1px solid #bcbcbc;
      }
      #jb-sidebar-left {
        width: 650px;
        height: 170px;
        padding: 20px;
        margin-right: 20px;
        margin-bottom: 20px;
        float: left;
        border: 1px solid #bcbcbc;
      }
      #jb-content {
        width: 450px;
        padding: 20px;
        margin-bottom: 20px;
        float: left;
        border: 1px solid #bcbcbc;
      }
      #jb-sidebar-right {
        width: 160px;
        padding: 20px;
        margin-bottom: 20px;
        float: right;
        border: 1px solid #bcbcbc;
      }
      #jb-footer {
        clear: both;
        padding: 20px;
        border: 1px solid #bcbcbc;
      }
    </style>
  </head>
 
 
<body>
    <div id="jb-container">
      <div id="jb-header">
        <h1>WELCOME</h1>
      </div>
      
     <div id="jb-sidebar-right">

       <?php
    session_start();

    $memberId=$_SESSION['ses_ID'];

         {       
                                    //만약 배열에 존재한다면
 
            echo $_SESSION['ses_username'].'님 안녕하세요<p/>';                   // name님 안녕하세요.
            echo "총 게시글 수 : <br>총 댓글수 : <br>";
            echo '<a href="./index.php">로그아웃 하기</a>';           //로그아웃 페이지 링크.
        }



 
         echo "</div>";
      
      

       
    

         if($memberId!="admin"){
            echo "<div id=\"jb-sidebar-left\">
            
              <ul>
       
                <li><a href=\"./userboard.php\" >게시판 모음</a></li><br>
                <li><a href=\"playlist.php\" >Playlist</a></li><br>
                <li><a href=\"albumreview.php\" >앨범 리뷰</a></li><br>
       
              </ul>
            </div>";
      }
      else
      {
         echo "<div id=\"jb-sidebar-left\">
            
              <ul>
       
                <li><a href=\"boardindex.php\" >게시판 관리</a></li><br>
                <li><a href=\"postingindex.php\" >포스팅 관리</a></li><br>
                <li><a href=\"albumindex.php\" >앨범 관리</a></li><br>
                <li><a href=\"songindex.php\" >곡 관리</a></li><br>
                <li><a href=\"adminalbumreview.php\" >앨범 리뷰 글 관리</a></li><br>
       
              </ul>
            </div>";
      }
      
   
 
 
?>

 
 
    </div>
  </body>
</html>
