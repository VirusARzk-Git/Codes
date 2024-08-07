function add(a, b) {
    return a + b;
}

console.log(add(1, 2));

function loginUserMessage(user) {
    if (!user) {
        return 'Please provide a valid user!';
    }
    return `Welcome ${user} !!`;
}

console.log(loginUserMessage('Aditya'));
console.log(loginUserMessage());

function calculateCartPrice(...prices) {
    return prices.reduce((total, price) => total + price);
}

console.log(calculateCartPrice(100, 200, 300, 400));

const user = {
    name: 'Aditya',
    age: 23,
}

function handleObject(anyobj) {
    if (!anyobj) {
        return 'Please provide a valid object!';
    }
    return `Welcome ${anyobj.name} and your age is ${anyobj.age}`;
}

console.log(handleObject(user));
console.log(handleObject({ name: 'John', age: 25 }));

const myArray = [200, 400, 700, 1100]

function getSecondValue(arr) {
    if (!arr) {
        return 'Please provide a valid array!';
    }
    return arr[1];
}

console.log(getSecondValue(myArray));