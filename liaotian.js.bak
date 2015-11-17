// 首先把2个人的时间变成array

// 假设这边生成了2个array

var xiaomo = new Array(15,16,17,23,24,25,26);
var xiaogu = new Array(1,2,3,4, 7,8,9,10,11, 15,16,17);
var l = 0;   // 最早起床时间
var r = 20;  // 最晚起床时间
// 然后循环一下，起床时间变化，看二者是否有交集
var ok = 0; // 代表可以起床的时间的选择数量
for (var i=l; i<=r ; i++ )  { // 不断迭代起床时间
    var xinxiaogu = xiaogu.slice(0);
    for (var j=0 ; j<xiaogu.length ; j++){
        xinxiaogu[j] += i;  // 变化小菇的空闲时间
    }
    console.log(xinxiaogu);
    has_time = 0;
    // 判断二者是否有聊天时间
    for (var k=0 ; k<xiaogu.length; k++){ // 对每个小菇时间进行判断
        for (var m=0; m<xiaomo.length; m++)  {//如果一致就可以
            if (xiaomo[m]==xinxiaogu[k]){
                has_time = 1;
            }
        }
    }
    ok = ok + has_time;
    }
console.log(ok);    // 输出可以的时间
