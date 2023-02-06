// Nama 		: Vincent Franstyo
// NIM			: 18221100
// Tanggal		: 17 Oktober 2022
// Topik 		: copyQueue
// Deskripsi	: menyalin isi dari Queue ke queue output

#include <stdio.h>
#include "copyqueue.h"
#include "queue.h"

// Menyalin queue.
void copyQueue(Queue *queueInput, Queue *queueOutput){
	// *queueOutput = *queueInput;

	if (isEmpty(*queueInput)){
		queueOutput = queueInput;
	}

	else{
		Queue qtemp;
		CreateQueue(&qtemp);

		int len = length(*queueInput);
		while (len != 0){
			ElType val;
			dequeue(queueInput, &val);
			enqueue(&qtemp, val);
			len--;
		}

		len = length(qtemp);
		while (len != 0){
			ElType val;
			dequeue(&qtemp, &val);
			enqueue(queueInput, val);
			enqueue(queueOutput, val);
			len--;
		}
	}
	
}
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/