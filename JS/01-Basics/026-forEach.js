const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let sum = 0;
arr.forEach((e) => {
    sum += e;
});
console.log(sum);

const Sum = arr.reduce((acc, e) => {
    console.log(`acc: ${acc}, e: ${e}`);
    return acc + e;
}, 0);
console.log(Sum);

let arr2 = arr.filter((e) => e % 2 === 0);
console.log(arr2);

let arr3 = arr.map((e) => { return e % 2 ? e * 2 : e * 3; });
console.log(arr3);

let arr23 = arr.filter((e) => e % 2).map((e) => e * 3);
console.log(arr23);

let arr4 = arr.reduce((acc, e) => acc + e, 0);
console.log(arr4);

let arr5 = arr.reduce((acc, e) => {
    if (e % 2 === 0) {
        acc.push(e);
    }
    return acc;
}, []);
console.log(arr5);

let arr6 = arr.reduce((acc, e) => {
    if (e % 2 === 0) {
        acc.push(e * 2);
    }
    else {
        acc.push(e * 3);
    }
    return acc;
}
    , []);
console.log(arr6);