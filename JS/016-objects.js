// const tinderUser = new Object();
const tinderUser = {}
console.log(tinderUser);

tinderUser.id = 'abc123';
tinderUser.name = 'Aditya';
tinderUser.age = 23;

console.log(tinderUser);

const regularUser = {
    email: 'aditya@gmail.com',
    fullname: {
        first: 'Aditya',
        last: 'Raj'
    },
}

console.log(regularUser.fullname);


const obj1 = { 1: 'one', 2: 'two', 3: 'three' };
const obj2 = { 4: 'four', 5: 'five', 6: 'six' };

const obj3 = { obj1, obj2 };
console.log(obj3);

const obj4 = Object.assign({}, obj1, obj2);
console.log(obj4);

const obj5 = { ...obj1, ...obj2 };
console.log(obj5);

console.log(tinderUser)
console.log(Object.keys(tinderUser))
console.log(Object.values(tinderUser))
console.log(Object.entries(tinderUser))

console.log(tinderUser.hasOwnProperty('name'))
console.log(tinderUser.hasOwnProperty('email'))

const course = {
    title: 'JavaScript',
    price: 999,
    courseInstrucor: 'Aditya',
    courseDuration: '3 months'
}

const { title: t, price : p, ...rest } = course;
console.log(t, p, rest);

const { courseInstrucor, courseDuration } = course;
console.log(courseInstrucor, courseDuration);