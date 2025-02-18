// Async

async function getTitle(url) {
  let response = await fetch(url);
  let html = await response.test();
  return html.match(/<title>([\s\S]+)<\/title>/i)[1];
}

getTitle("https://tc39.github.io/ecma262/")
  .then(console.log)
  .catch(console.error);

// await 最好放在try...catch中
// 因为await会等待promise的状态改变，如果promise状态变为rejected，await会抛出错误

async function fetchData() {
  try {
    let response = await fetch("coffee.jpg");

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    let data = await response.json();
    console.log(data);
  } catch (e) {
    console.log(e);
  }
}

fetchData();

// 串行请求
async function fetchData() {
  try {
    let response1 = await fetch("https://jsonplaceholder.typicode.com/todos/1");
    let data1 = await response1.json();
    console.log(data1);

    let response2 = await fetch("https://jsonplaceholder.typicode.com/todos/2");
    let data2 = await response2.json();
    console.log(data2);
  } catch (error) {
    console.error("发生错误:", error);
  }
}

fetchData();

// 并行请求
async function fetchData() {
  try {
    let [response1, response2] = await Promise.all([
      fetch("https://jsonplaceholder.typicode.com/todos/1"),
      fetch("https://jsonplaceholder.typicode.com/todos/2"),
    ]);

    let data1 = await response1.json();
    let data2 = await response2.json();

    console.log(data1);
    console.log(data2);
  } catch (error) {
    console.error("发生错误:", error);
  }
}

fetchData();
