#include "head.h"

int signup(struct member *mp) {
	MYSQL connect = { 0 };
	mysql_init(&connect);
	char buffer[200];
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };
	

	connection = mysql_real_connect(&connect, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3308, NULL, 0);

	mysql_query(connection, "select * from member");
	result = mysql_store_result(connection);

	while ((row = mysql_fetch_row(result)) != NULL) {
		
		if (!strcmp(mp->email, row[1])) {
			return 2;
		}
	}
	mysql_free_result(result);

	if (!strcmp(mp->name, "") || !strcmp(mp->email, "") || !strcmp(mp->pw, "")) {
		return 4;
	}else if (strcmp(mp->pw, mp->chPw)) {
		return 3;
	}
	
	else 
	sprintf(buffer, "insert into member (email, name, password) values" "('%s', '%s', '%s')", mp->email, mp->name, mp->pw);
	mysql_query(connection, buffer);
	return 1;
}
