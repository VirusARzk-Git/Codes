function add1(a, b) {
    return a + b;
}
console.log(add1(1, 2));

const add2 = function (a, b) {
    return a + b;
}
console.log(add2(1, 2));

const add3 = (a, b) => a + b;
console.log(add3(1, 2));

const add4 = (a, b) => (a + b);
console.log(add4(1, 2));

