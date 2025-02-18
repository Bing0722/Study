// 回调函数

function fechData(callback) {
  setTimeout(() => {
    console.log("fetch data");
    callback();
  }, 1000);
}

fechData(() => {
  console.log("do something");
});

// Promise
/**
 * 1. Promise 是一个构造函数，自己身上有all、reject、resolve这几个方法
 * 2. Promise 上有原型方法 then
 * 3. Promise 一旦状态改变就不能再改变
 * 4. Promise 有三种状态：pending、fulfilled、rejected
 * 5. Promise 会返回一个新的 Promise 实例
 * 6. Promise 可以链式调用
 * 7. Promise 可以捕获内部异常
 */

let promise = new Promise((resolve, reject) => {
  let flag = true;
  if (flag) {
    resolve("success");
  } else {
    reject("error");
  }
});

// then 方法 有两个参数，第一个是成功的回调，第二个是失败的回调
// catch 方法 只有失败的回调
// finally 无论成功还是失败都会执行
promise
  .then((result) => {
    console.log(result);
  })
  .catch((error) => {
    console.log(error);
  })
  .finally(() => {
    console.log("finally");
  });

// Promise.all
let p1 = new Promise((resolve, reject) => {
  resolve("p1");
});

let p2 = new Promise((resolve, reject) => {
  resolve("p2");
});

Promise.all([p1, p2]).then((result) => {
  console.log(result);
});

// Promise.race
let p3 = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("p3");
  }, 1000);
});

let p4 = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("p4");
  }, 2000);
});

Promise.race([p3, p4]).then((result) => {
  console.log(result);
});
