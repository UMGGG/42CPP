
#include "easyfind.hpp"

int	main( void )
{
	{
		std::cout << "--- CONTAINER VECTOR ---" << std::endl;
		int	vector_arr[] = {1, 2, 3, 3, 4, 5};
		std::vector<int> vector_container( vector_arr, vector_arr + (sizeof(vector_arr)/sizeof(int)) );

		try{ // search 3 & print form 3 to end
			std::vector<int>::iterator v_iter = easyfind(vector_container, 3);

			while (v_iter != vector_container.end())
				std::cout << *(v_iter++) << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		try{ // search 400 & fail exception
			std::vector<int>::iterator v_iter = easyfind(vector_container, 400);

			while (v_iter != vector_container.end())
				std::cout << *(v_iter++) << std::endl;
		}
		catch (const std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	//
	{
		std::cout << "--- CONTAINER LIST ---" << std::endl;
		int	list_arr[] = {200, -3, 1, 300, -40, -500};
		std::list<int> list_container( list_arr, list_arr + (sizeof(list_arr)/sizeof(int)) );

		try{ // search -3 & print form -3 to end
			std::list<int>::iterator l_iter = easyfind< std::list<int> >(list_container, -3);

			while (l_iter != list_container.end())
				std::cout << *(l_iter++) << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		try{ // search 89 & fail exception
			std::list<int>::iterator l_iter = easyfind< std::list<int> >(list_container, 89);

			while (l_iter != list_container.end())
				std::cout << *(l_iter++) << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	//
	{
		std::cout << "--- CONTAINER DEQUE ---" << std::endl;
		int	deque_arr[] = {5201, 326, -1, 330, 488, -503};
		std::deque<int> deque_container( deque_arr, deque_arr + (sizeof(deque_arr)/sizeof(int)) );

		try{ // search 5201 & print form 5201 to end
			std::deque<int>::iterator d_iter = easyfind< std::deque<int> >(deque_container, 5201);

			while (d_iter != deque_container.end())
				std::cout << *(d_iter++) << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		try{ // search -3 & fail exception
			std::deque<int>::iterator d_iter = easyfind< std::deque<int> >(deque_container, -3);

			while (d_iter != deque_container.end())
				std::cout << *(d_iter++) << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}

	// {
	// 	/* --- NOT HAVE ITERATOR --- */
	// 	std::stack<int> a;

	// 	/* try1 */
	// 	try{
	// 		easyfind<std::stack<int>(a, 5201);
	// 	}
	// 	catch(const std::exception& e){
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }

	return 0;
}
