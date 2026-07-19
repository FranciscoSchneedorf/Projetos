function mostrarnome(){
    var nome = document.getElementById("nome").value;

    document.getElementById("mensagem").innerHTML = "Olá, " + nome + "! Sua mensagem foi enviada.";

}