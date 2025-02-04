#include <iostream>
#include "src/Produto/Produto.hpp"
#include "src/Produto/ProdutoDigital.hpp"
#include "src/Produto/ProdutoFisico.hpp"
#include "src/Produto/GerenciadorProdutos.hpp"
#include <vector>
#include "src/Usuario/Cliente.hpp"
#include "src/Usuario/Usuario.hpp"

enum return_status
{
    PRODUCT_FOUND,
    PRODUCT_NOT_FOUND,
};

int mostrar(Produto *produto)
{
    if (produto == nullptr)
    {
        std::cout << "Produto não encontrado" << std::endl;
        return PRODUCT_NOT_FOUND;
    }
    else
    {
        produto->print();
        return PRODUCT_FOUND;
    }
}

void test1()
{
    GerenciadorProdutos gerenciador;

    std::cout << "Teste para ver se os produtos DVD e Filme estão sendo inseridos" << std::endl;
    std::cout << "******************************************************************************" << std::endl;
    // Teste para ver se os produtos DVD e Filme estão sendo inseridos
    // ****************************************************************************** //
    Produto *dvd = new ProdutoFisico("DVD", "DVD virgem", 1.50, 1);
    Produto *filme = new ProdutoDigital("Matrix", "Filme dublado", 5, 1);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);

    gerenciador.mostrarProdutos();
    // ****************************************************************************** //

    // Teste de alteração do valor de produto
    // ****************************************************************************** //
    gerenciador.buscaProduto("Matrix")->print();
    Produto *ret = gerenciador.buscaProduto("DVD");
    if (ret != nullptr)
    {
        ret->print();
    }

    gerenciador.atualizarProduto(dvd, "DVD Aurora Blueray", "", -1, -1);

    gerenciador.mostrarProdutos();
    // ****************************************************************************** //
}

void test2()
{
    GerenciadorProdutos gerenciador;

    Produto *dvd = new ProdutoFisico("DVD", "DVD virgem", 1.50, 1);
    Produto *filme = new ProdutoDigital("Matrix", "Filme dublado", 5, 1);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);

    gerenciador.mostrarProdutos();
    // ****************************************************************************** //
    // Verificar produtos não encontrados
    // ****************************************************************************** //
    Produto *produto = gerenciador.buscaProduto("MadMax");
    mostrar(produto);
}

void test3()
{
    GerenciadorProdutos gerenciador;

    Produto *dvd = new ProdutoFisico("DVD", "DVD virgem", 1.50, 1);
    Produto *filme = new ProdutoDigital("Matrix", "Filme dublado", 5, 1);
    Produto *tenis = new ProdutoFisico("Tenis", "Tenis de corrida Nike", 357.35, 2);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);
    gerenciador.cadastrarProduto(tenis);

    gerenciador.deletarProduto("Matrix");
    std::cout << "Estou passando por aqui";

    // gerenciador.mostrarProdutos();
}

void test4()
{
    GerenciadorProdutos gerenciador;
    Produto *dvd = new ProdutoFisico("DVD", "DVD virgem", 1.50, 1);
    Produto *filme = new ProdutoDigital("Matrix", "Filme dublado", 5, 1);
    Produto *tenis = new ProdutoFisico("Tenis", "Tenis de corrida Nike", 357.35, 2);

    gerenciador.cadastrarProduto(dvd);
    gerenciador.cadastrarProduto(filme);
    gerenciador.cadastrarProduto(tenis);

    Usuario *cliente = new Cliente("Marcos Paulo", "teste@gmail.com");
    


}
int main()
{
    test1();
    test2();
    test3();
    return 0;
}
