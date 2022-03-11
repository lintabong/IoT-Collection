package com.example.waterflowmonitoring;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class MainActivity extends AppCompatActivity {

    TextView val1;
    TextView val2;
    TextView val3;

    FirebaseDatabase database = FirebaseDatabase.getInstance();
    DatabaseReference myRef = database.getReference();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        val1 = (TextView) findViewById(R.id.val1);
        val2 = (TextView) findViewById(R.id.val2);
        val3 = (TextView) findViewById(R.id.val3);

        myRef.child("user").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot snapshot) {
                String value1 = snapshot.child("wf1").getValue(String.class);
                String value2 = snapshot.child("wf2").getValue(String.class);
                String value3 = snapshot.child("wf3").getValue(String.class);

                val1.setText(value1);
                val2.setText(value2);
                val3.setText(value3);
            }

            @Override
            public void onCancelled(DatabaseError error) {

            }
        });


    }
}
