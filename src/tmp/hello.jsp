<body>
    <p class="hx">Hello</p>
</body>
<script src="./js/jquery-3.7.1.js"></script>
<script>
    $(() => {
        let dom = document.getElementsByClassName("hx")[0];
        $(dom); // 这就是一个jQuery获取节点的对象

        $("#text");
        $("<a></a>"); // 这就是创建了元素节点
    });
</script>