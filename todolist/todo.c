#include "head.h"

struct todo* todo(struct member *mp, struct todo doArr[], struct todo *tp, int* cp) {
	MYSQL connect = { 0 };
	mysql_init(&connect);
	char buffer[200];
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };

	TODO t1 = {0, ""};


	connection = mysql_real_connect(&connect, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3308, NULL, 0);

	mysql_query(connection, "select * from todo");
	result = mysql_store_result(connection);

	while ((row = mysql_fetch_row(result)) != NULL) {
		if (mp->id == atoi(row[0])) {  //들어온 id를 정수형으로 변환
			t1.id = atoi(row[0]);
			strcpy(t1.content, row[2]);
			printf("할당");
			doArr[0] = t1;
			(*cp)++;
		}
	}
	mysql_free_result(result);

	sprintf(buffer, "insert into todo (id, content) values" "('%d', '%s')", tp->id, tp->content);
	mysql_query(connection, buffer);
	return 1;
}