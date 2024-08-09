let myDate = new Date();
console.log(myDate);
console.log(typeof myDate);
console.log(myDate.getDate());

// 0 - Sunday
// 1 - Monday
// 2 - Tuesday
// 3 - Wednesday
// 4 - Thursday
// 5 - Friday
// 6 - Saturday
console.log(myDate.getDay());
console.log(myDate.getFullYear());
// console.log(myDate.getHours());
// console.log(myDate.getMinutes());
// console.log(myDate.getSeconds());
// console.log(myDate.getTime());
// console.log(myDate.getMilliseconds());

// 0 - January
// 1 - February
// 2 - March
// 3 - April
// 4 - May
// 5 - June
// 6 - July
// 7 - August
// 8 - September
// 9 - October
// 10 - November
// 11 - December

// console.log(myDate.getMonth());
console.log(myDate.toDateString());
console.log(myDate.toTimeString());
console.log(myDate.toLocaleString());
console.log(myDate.toLocaleDateString());
console.log(myDate.toLocaleTimeString());
console.log(myDate.toString());
console.log(myDate.toUTCString());
console.log(myDate.toISOString());

let myCreatedDate = new Date('2003-07-22');
let myCreatedDate2 = new Date('July 22 2003');
let myCreatedDate3 = new Date('07/22/2003');
let myCreatedDate4 = new Date('22-07-2003');
let myCreatedDate5 = new Date(2003, 6, 22);
let myCreatedDate6 = new Date(2003, 6, 22, 10, 30, 45);
console.log(myCreatedDate.toDateString());
console.log(myCreatedDate2.toDateString());
console.log(myCreatedDate3.toDateString());
console.log(myCreatedDate4.toDateString());
console.log(myCreatedDate5.toDateString());
console.log(myCreatedDate6.toString());

let myTimestamp = Date.now();
console.log(myTimestamp);
console.log(new Date(myTimestamp).toDateString());
console.log(new Date(myTimestamp).toTimeString());