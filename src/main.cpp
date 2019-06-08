#include "./include/input.h"
#include <time.h>

using namespace std;

int main(int argc, char* argv[]){
    srand(time(NULL));

    if (argc != 2){
        printf("\nErro parametro, usar segundo sintaxe:\n\n");
        printf(" %s [input file]\n\n", argv[0]);
        exit(ERRO_INPUT_FILE_ARGS);
    }

    input_args(argv[1]);
    start_simulation();

    std::cout << '\n';
    
    for (int i=0; i < QUEUE_WAIT; i++){
        printf("Fila [%d] = %ld\n", i, SM_queue_vasos[i].size());
    }

    std::cout << '\n';

    for (Artesao* artesao: SM_Artesao) {
        printf("Artesao ID: %d, ociosidade: %ld\n", artesao->get_id(), artesao->get_time_ociosity());
    }

    std::cout << '\n';

    for (Especialista* especialista: SM_Especialista) {
        printf("Especialista ID: %d, ociosidade: %ld\n", especialista->get_id(), especialista->get_time_ociosity());
    }

    std::cout << '\n';

    std::cout << "Time atual: "        << SM_time_simulation      << '\n';
    std::cout << "Time Final: "        << SM_final_time_simulation << '\n';
    std::cout << '\n';
    std::cout << "Vasos Gerados: "     << last_id_vaso            << '\n';
    std::cout << "Vasos Finalizados: " << SM_vaso_finish.size()    << '\n';
    std::cout << '\n';
    printf("Massa: %d, Pedra: %d, Espaço: %d\n\n", SM_massa, SM_pedra, SM_espaco_secagem);
    return 0;
}
