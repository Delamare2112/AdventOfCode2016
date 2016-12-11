using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
	public float speed;
	public GameObject exposionEffect;

	void Start ()
	{
		GetComponent<Rigidbody> ().AddForce (transform.forward * speed);
	}

	void OnCollisionEnter(Collision other)
	{
		Instantiate (exposionEffect, transform.position, Quaternion.Euler(-90, 0, 0));
		Destroy (gameObject);
	}
}
