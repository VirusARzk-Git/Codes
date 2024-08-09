const day = 2;
let dayType;

switch (day) {
    case 1:
        dayType = 'Sunday';
        break;
    case 2:
        dayType = 'Monday';
        break;
    case 3:
        dayType = 'Tuesday';
        break;
    case 4:
        dayType = 'Wednesday';
        break;
    case 5:
        dayType = 'Thursday';
        break;
    case 6:
        dayType = 'Friday';
        break;
    case 7:
        dayType = 'Saturday';
        break;
    default:
        dayType = 'Invalid day';
}

console.log(dayType);