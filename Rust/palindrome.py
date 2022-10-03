fn main() {
    println!("{}", is_palindrome(123321));
}

fn is_palindrome(x: i32) -> bool{
    if x < 0 || (x % 10 == 0 && x != 0){
        return false
    }
    let mut aux: i32 = x;
    let mut reverted_num: i32 = 0;
    while aux > reverted_num {
        reverted_num = reverted_num * 10 + aux.rem_euclid(10);
        aux = aux / 10;
    }

    return aux == reverted_num || reverted_num/10 == aux
}