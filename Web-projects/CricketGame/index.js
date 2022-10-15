let a = document.getElementById("a").value;
let b = document.getElementById("b").value;
// alert("JS Connected");
function Mul(){
	let c = a*b;
	// alert(`a = ${a}\nType of a = ${typeof(a)}\nMultiplication = ${c}`);
	document.querySelector('.answer').textContent = `The Multiplication is: ${c}`;
}
function Div(){
	let d = a/b;
	document.querySelector('.answer').textContent = `The Division is: ${d}`
}
let e = document.getElementById("e").value;
let f = document.getElementById("f").value;
e = Number(e);
f = Number(f);
function Q5(){
	if(e==f){
		document.querySelector(".Q5").textContent = `Both The Numbers are same, so the tripple value is ${3*e}`;
	}
	else{
		e = e+f;
		document.querySelector(".Q5").textContent = `Both The Numbers are different, so the tripple value is ${e}`;

	}
}
function Q6(){
	let g = Number(document.getElementById('g').value);
	alert(`${typeof(g)}`);
	if(g<90 && g>0){
		alert('The Angle is acute');
	}
	else if(g>90 || g<0){
		alert('The Angle is obtuce');
	}
	else if(g == 90){
		alert('The Angle is a Right Angle');
	}
}
