const myArr = [1, 2, 3, 4, 5];
console.log(myArr);

const myArr2 = new Array(1, 2, 3, 4, 5);
console.log(myArr2);

const myArr3 = ['Aaditya', 23, true, null, undefined, {a: 1, b: 2}, [1, 2, 3, 4, 5]];
console.log(myArr3);

myArr.push(6);
console.log(myArr);

myArr.pop();
console.log(myArr);

myArr.unshift(11);
console.log(myArr);

myArr.shift();
console.log(myArr);

console.log(myArr.indexOf(3));
console.log(myArr.indexOf(7));

console.log(myArr.includes(3));
console.log(myArr.includes(7));

console.log(myArr.reverse());
console.log(myArr);

console.log(myArr.concat(myArr2));
console.log(myArr);

const myArr4 = myArr.join(' ');
console.log(myArr4);

console.log("A ", myArr);

const myArr5 = myArr.slice(1, 4);
console.log(myArr5);
console.log("B ", myArr);

const myArr6 = myArr.splice(1, 2);
console.log(myArr6);
console.log("C ", myArr);